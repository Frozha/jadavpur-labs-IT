package com.hw;
import java.io.*;
import javax.servlet.*;            
import javax.servlet.http.*;        
import javax.servlet.annotation.*;

@WebServlet("/sayhello")

public class HelloWorld extends HttpServlet {

   @Override
   public void doGet(HttpServletRequest request, HttpServletResponse response)
         throws IOException, ServletException {
 
      response.setContentType("text/html; charset=UTF-8");

      PrintWriter out = response.getWriter();  // throw IOException

      out.println("""
            <!DOCTYPE html>
            <html>
            <head><title>Hello, World</title></head>
            <body>
              <h1>Hello, world!</h1>
              <p>Request URI: %s</p>
              <p>Protocol: %s</p>
              <p>PathInfo: %s</p>
              <p>Remote Address: %s</p>
              <p>A Random Number: <strong>%f</strong></p>
            </body>
            </html>
            """.formatted(request.getRequestURI(), request.getProtocol(),
                          request.getPathInfo(), request.getRemoteAddr(),
                          Math.random()));  
      out.close();  
      
    
      System.out.println("hello world, to Tomcat!");   // Check Tomcat's console for this message
   }
}
