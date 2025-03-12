package com.hw;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet("/chatroom")
public class ChatroomServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Extract path info to get the chatroom hash
        String pathInfo = request.getPathInfo(); // e.g., "/chatroom/{hash}"
        String hash = pathInfo != null && pathInfo.length() > 1 ? pathInfo.substring(1) : null;

        if (hash == null) {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Chatroom hash not provided.");
            return;
        }

        // Get username and roomHash from the form data
        String username = request.getParameter("username");
        String roomHash = request.getParameter("roomHash");

        // If the roomHash is empty (i.e., user is creating a new chatroom), use the hash of the username
        if (roomHash == null || roomHash.isEmpty()) {
            roomHash = hashString(username); // Hash the username if no roomHash provided
        }

        // Save the roomHash and username if needed (you could store them in session or database)
        // Here we'll use session to simulate the user's chatroom context
        HttpSession session = request.getSession();
        session.setAttribute("username", username);
        session.setAttribute("roomHash", roomHash);

        // Now redirect the user to the chatroom page
        response.sendRedirect("/chatroom/" + roomHash); // Redirect to the WebSocket chatroom page
    }

    // Method to generate a room hash from the username (simulating creation or joining of a room)
    private String hashString(String str) {
        try {
            java.security.MessageDigest md = java.security.MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(str.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hashBytes) {
                hexString.append(String.format("%02x", b));
            }
            return hexString.toString().substring(0, 6); // Return only the first 6 characters of the hash
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    // Method to generate the chatroom page (this will be served after successful form submission)
    private String generateChatroomPage(String roomHash) {
        // Generating a chatroom page with a WebSocket connection for real-time messaging
        return "<!DOCTYPE html>" +
                "<html lang='en'>" +
                "<head>" +
                "<meta charset='UTF-8'>" +
                "<meta name='viewport' content='width=device-width, initial-scale=1.0'>" +
                "<title>Chatroom</title>" +
                "</head>" +
                "<body>" +
                "<h2>Welcome to Chatroom: " + roomHash + "</h2>" +
                "<div id='chatMessages'></div>" +
                "<input type='text' id='messageInput' placeholder='Type a message' />" +
                "<button onclick='sendMessage()'>Send</button>" +

                "<script>" +
                "    const roomHash = '" + roomHash + "';" +
                "    const socket = new WebSocket('ws://' + window.location.host + '/chatroom/' + roomHash);" +
                "    const chatMessages = document.getElementById('chatMessages');" +

                "    socket.onmessage = function(event) {" +
                "        const message = document.createElement('p');" +
                "        message.textContent = event.data;" +
                "        chatMessages.appendChild(message);" +
                "    };" +

                "    function sendMessage() {" +
                "        const messageInput = document.getElementById('messageInput');" +
                "        const message = messageInput.value;" +
                "        socket.send(message);" +
                "        messageInput.value = '';" +
                "    }" +
                "</script>" +
                "</body>" +
                "</html>";
    }
}
