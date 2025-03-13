package com.hw;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

public class ChatroomServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String pathInfo = request.getPathInfo();
        String username = (String) request.getParameter("username");
        String hash = (String) request.getParameter("roomHash"); 

        if (hash == null) {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Invalid chatroom.");
            return;
        }
        if (username == null) {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Invalid username.");
            return;
        }

        response.setContentType("text/html");
        response.getWriter().write(generateChatroomPage(hash, username));
    }

private String generateChatroomPage(String roomHash, String username) {
    return "<!DOCTYPE html>" +
            "<html lang='en'>" +
            "<head>" +
            "<meta charset='UTF-8'>" +
            "<meta name='viewport' content='width=device-width, initial-scale=1.0'>" +
            "<title>Chatroom</title>" +
            "<style>" +
            "    #chatMessages { border: 1px solid #ddd; padding: 10px; height: 300px; overflow-y: auto; }" +
            "    .message { padding: 5px; border-radius: 5px; margin-bottom: 5px; }" +
            "    .self { background-color:rgb(241, 239, 122); text-align: right; }" +
            "    .other { background-color: #bfbebb; text-align: left; }" +
            "</style>" +
            "</head>" +
            "<body>" +
            "<h2>Welcome, " + username + "! Chatroom ID: " + roomHash + "</h2>" +
            "<div id='chatMessages'></div>" +
            "<input type='text' id='messageInput' placeholder='Type a message' />" +
            "<button onclick='sendMessage()'>Send</button>" +

            "<script>" +
            "    const roomHash = '" + roomHash + "';" +
            "    const socket = new WebSocket('ws://' + window.location.host + '/chatroom/chat/' + roomHash);"  +
            "    const chatMessages = document.getElementById('chatMessages');" +

            "    socket.onmessage = function(event) {" +
            "        const message = document.createElement('p');" +
            "        message.textContent = event.data;" +
            "        message.classList.add('message', 'other');" +
            "        chatMessages.appendChild(message);" +
            "        chatMessages.scrollTop = chatMessages.scrollHeight;" +
            "    };" +

            "    function sendMessage() {" +
            "        const messageInput = document.getElementById('messageInput');" +
            "        const message = '" + username + ": ' + messageInput.value;" +
            "        socket.send(message);" +
            "        messageInput.value = '';" +
            "    }" +
            "</script>" +
            "</body>" +
            "</html>";
}

}
