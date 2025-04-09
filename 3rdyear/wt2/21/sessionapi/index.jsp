<%@ page contentType="text/html; charset=UTF-8" language="java" %>
<%@ page import="javax.servlet.http.*, java.util.*" %>
<html>
<head>
    <title>Number Counter with Next and Prev</title>
</head>
<body>
    
    <%
        // Get the session object
        HttpSession mysession = request.getSession(true);
        
        // Get the counter from the session, if it exists
        Integer counter = (Integer) mysession.getAttribute("counter");
        if (counter == null) {
            counter = 0;  // Default to 0 if no counter is stored in session
        }

        // Check the action (Prev or Next) submitted via the form
        String action = request.getParameter("action");
        if (action != null) {
            if ("Next".equals(action)) {
                counter++;  // Increment the counter
            } else if ("Prev".equals(action)) {
                counter--;  // Decrement the counter
            }

            // Save the updated counter in the session
            mysession.setAttribute("counter", counter);
        }
    %>


        <h1>Current Counter Value: <%= counter %></h1>
        <form method="post" action="index.jsp">
            <input type="submit" name="action" value="Prev" />
            <input type="submit" name="action" value="Next" />
        </form>


</body>
</html>
