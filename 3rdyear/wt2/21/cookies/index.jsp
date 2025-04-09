<%@ page contentType="text/html; charset=UTF-8" language="java" %>
<%@ page import="javax.servlet.http.*, java.util.*" %>
<html>
<head>
    <title>Number Counter with Next and Prev</title>
</head>
<body>
    
    <%
        Cookie[] cookies = request.getCookies();
        int counter = 0; // Default counter value if no cookie exists

        // Check if the counter cookie exists
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if ("counter".equals(cookie.getName())) {
                    try {
                        counter = Integer.parseInt(cookie.getValue());
                    } catch (NumberFormatException e) {
                        counter = 0; // Reset if there's a parsing error
                    }
                    break;
                }
            }
        }

        // Check the action (Prev or Next) submitted via the form
        String action = request.getParameter("action");
        if (action != null) {
            if ("Next".equals(action)) {
                counter++;  // Increment the counter
            } else if ("Prev".equals(action)) {
                counter--;  // Decrement the counter
            }
        }

        // Set the updated counter value in the cookie
        Cookie counterCookie = new Cookie("counter", String.valueOf(counter));
        counterCookie.setMaxAge(60 * 60 * 24); // Cookie will expire in 1 day
        response.addCookie(counterCookie);
    %>


        <h1>Current Counter Value: <%= counter %></h1>
        <form method="post" action="index.jsp">
            <input type="submit" name="action" value="Prev" />
            <input type="submit" name="action" value="Next" />
        </form>

</body>
</html>
