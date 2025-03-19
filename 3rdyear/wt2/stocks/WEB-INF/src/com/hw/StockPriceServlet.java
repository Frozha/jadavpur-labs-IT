package com.hw;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class StockPriceServlet extends HttpServlet {

    private static final double INITIAL_PRICE_AAPL = 150.0;  
    private static final double INITIAL_PRICE_GOOG = 125.0; 

    private double generateRandomPrice(double currentPrice) {
        double fluctuation = (Math.random() * 0.04) - 0.02; // Random fluctuation between -2% and +2%
        return currentPrice * (1 + fluctuation);
    }

    // Handle SSE
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/event-stream");
        response.setCharacterEncoding("UTF-8");

        PrintWriter out = response.getWriter();
        response.flushBuffer();
        double currentAAPLPrice = INITIAL_PRICE_AAPL;
        double currentGOOGPrice = INITIAL_PRICE_GOOG;

        while (true) {
            try {
                currentAAPLPrice = generateRandomPrice(currentAAPLPrice);
                currentGOOGPrice = generateRandomPrice(currentGOOGPrice);
                String eventData = "{ \"AAPL\": " + currentAAPLPrice + ", \"GOOG\": " + currentGOOGPrice + " }";
                out.write("data: " + eventData + "\n\n");
                out.flush();
                Thread.sleep(1000);
            } catch (Exception e) {
                e.printStackTrace();
                break;
            }
        }
    }
}
