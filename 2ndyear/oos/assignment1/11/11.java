class Date {
    public int date = 1;
    public int month = 1;
    public int year = 1970;
    public boolean leap;

    static int[] month30 = {4, 6, 9, 11};
    static int[] month31 = {1, 3, 5, 7, 8, 10, 12};

    Date(int date, int month, int year) {
        this.date = date;
        this.month = month;
        this.year = year;
        this.leap = isLeap();
    }

    Date(int date) {
        this.date = date;
        this.leap = isLeap();
    }

    Date(int date, int month) {
        this.date = date;
        this.month = month;
        this.leap = isLeap();
    }

    Date() {
        this.leap = isLeap();
    }

    String previousDate() {
        if (date > 1) {
            return (date - 1) + "/" + month + "/" + year;
        } else if (month > 1) {
            int prevMonth = month - 1;
            int prevDate = (prevMonth == 2) ? (leap ? 29 : 28) : (contains(month31, prevMonth) ? 31 : 30);
            return prevDate + "/" + prevMonth + "/" + year;
        } else {
            int prevYear = year - 1;
            return "31/12/" + prevYear; 
        }
    }

    String nextDate() {
        int maxDays = getMaxDaysInMonth(month, leap);

        if (date < maxDays) {
            return (date + 1) + "/" + month + "/" + year;
        } else if (month < 12) {
            return "1/" + (month + 1) + "/" + year;
        } else {
            int nextYear = year + 1;
            return "1/1/" + nextYear; 
        }
    }

    String today() {
        return date + "/" + month + "/" + year;
    }

    private boolean isLeap() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    private boolean contains(int[] array, int value) {
        for (int num : array) {
            if (num == value) {
                return true;
            }
        }
        return false;
    }

    private int getMaxDaysInMonth(int month, boolean leap) {
        if (contains(month30, month)) {
            return 30;
        } else if (contains(month31, month)) {
            return 31;
        } else {
            return leap ? 29 : 28;
        }
    }
}

class Main {
    public static void main(String[] args) {
        // Create date object
        Date todayDate = new Date(22, 1, 2024);

        // Print next and previous date
        System.out.println("Today: " + todayDate.today());
        System.out.println("Previous Date: " + todayDate.previousDate());
        System.out.println("Next Date: " + todayDate.nextDate());
    }
}

