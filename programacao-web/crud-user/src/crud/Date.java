package crud;

public class Date {

    private int day;
    private int month;
    private int year;

    private int[] months30days = {4, 6, 9, 11};

    public Date(int day, int month, int year) {
        this.setDay(day);
        this.setYear(year);
        this.setMonth(month);
    }

    public int getDay() {
        return this.day;
    }

    public void setDay(int day) throws IllegalArgumentException {
        if (day < 1 | day > 31) {
            throw new IllegalArgumentException("invalid date");
        }
        this.day = day;
    }

    public int getMonth() {
        return this.month;
    }

    public void setMonth(int month) throws IllegalArgumentException {
        if (month < 1 || month > 12) {
            throw new IllegalArgumentException("invalid date");
        }
        if (Operand.in(month, this.months30days) && this.getDay() > 30) {
            throw new IllegalArgumentException("invalid date");
        }
        if (month == 2 && this.getDay() > 29) {
            throw new IllegalArgumentException("invalid date");
        }
        if (!isLeapYear(this.getYear()) && this.getDay() > 28) {
            throw new IllegalArgumentException("invalid date");
        }
        this.month = month;
    }

    public int getYear() {
        return this.year;
    }

    public void setYear(int year) throws IllegalArgumentException{
        if (year < 1) {
            throw new IllegalArgumentException("invalid date");
        }
        this.year = year;
    }

    public static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    public String toString() {
        return this.getDay() + "/" + this.getMonth() + "/" + this.getYear();
    }
}

class Operand {
	public static boolean in(int value, int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }
}

