package com.hw;

import javax.websocket.*;
import javax.websocket.server.PathParam;
import javax.websocket.server.ServerEndpoint;
import java.io.IOException;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

@ServerEndpoint(value = "/chat/{hash}")
public class ChatroomWebSocket {

    private static final Map<String, Set<Session>> rooms = new ConcurrentHashMap<>();

    @OnOpen
    public void onOpen(Session session, @PathParam("hash") String hash) {
        rooms.putIfAbsent(hash, new HashSet<>());
        synchronized (rooms.get(hash)) {
            rooms.get(hash).add(session);
        }

        try {
            session.getBasicRemote().sendText("✅ Connected to chatroom: " + hash);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @OnMessage
    public void onMessage(Session session, String message, @PathParam("hash") String hash) {
        Set<Session> roomClients = rooms.get(hash);

        if (roomClients != null) {
            synchronized (roomClients) {
                for (Session client : roomClients) {
                    try {
                        client.getBasicRemote().sendText(message);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    @OnClose
    public void onClose(Session session, @PathParam("hash") String hash) {
        Set<Session> roomClients = rooms.get(hash);
        if (roomClients != null) {
            synchronized (roomClients) {
                roomClients.remove(session);
                if (roomClients.isEmpty()) {
                    rooms.remove(hash);
                }
            }
        }
    }

    @OnError
    public void onError(Session session, Throwable throwable) {
        throwable.printStackTrace();
    }
}
