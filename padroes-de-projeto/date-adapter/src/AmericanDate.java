public class AmericanDate extends Date {

    public AmericanDate(int year, int month, int day) {
        this.setDay(day);
        this.setYear(year);
        this.setMonth(month);
    }

    public void setDayMonth(int day, int month) {
        this.setDay(day);
        this.setMonth(month);
    }

    public void setMonthYear(int month, int year) {
        this.setYear(year);
        this.setMonth(month);
    }

    public void setDayYear(int day, int year) {
        this.setDay(day);
        this.setYear(year);
        this.setMonth(this.month);  // setting the month again to validate the new day and year
    }

    public void setDayMonthYear(int day, int month, int year) {
        this.setDay(day);
        this.setYear(year);
        this.setMonth(month);
    }
}
