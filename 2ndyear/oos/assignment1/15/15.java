class Tollbooth {
    private int carsWithoutPayment;
    private int totalCarsPassed;
    private double totalCashCollected;

    Tollbooth() {
        carsWithoutPayment = 0;
        totalCarsPassed = 0;
        totalCashCollected = 0;
    }

    public void carPasses(boolean paid) {
        totalCarsPassed++;

        if (!paid) {
            carsWithoutPayment++;
        } else {
            totalCashCollected =totalCashCollected+ 50.0;   
        }
    }

    public void displayResults() {
        System.out.println("Total number of cars passed by without paying: " + carsWithoutPayment);
        System.out.println("Total number of cars passed by: " + totalCarsPassed);
        System.out.println("Total cash collected: Rs. " + totalCashCollected);
    }
}

class Main{
    public static void main(String[] args) {
        Tollbooth tollbooth = new Tollbooth();

        tollbooth.carPasses(true);
        tollbooth.carPasses(false);
        tollbooth.carPasses(true);

        tollbooth.displayResults();
    }
}

