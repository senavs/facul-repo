public class Time {

    private int hour;
    private int minute;
    private int second;

    public Time(int hour, int minute, int second) {
        this.setHour(hour);
        this.setMinute(minute);
        this.setSecond(second);
    }

    public int getHour() {
        return this.hour;
    }

    public void setHour(int hour) throws IllegalArgumentException {
        if (hour < 0 | hour > 23) {
            throw new IllegalArgumentException("invalid time");
        }
        this.hour = hour;
    }

    public int getMinute() {
        return this.minute;
    }

    public void setMinute(int minute) throws IllegalArgumentException {
        if (minute < 0 | minute > 59) {
            throw new IllegalArgumentException("invalid time");
        }
        this.minute = minute;
    }

    public int getSecond() {
        return this.second;
    }

    public void setSecond(int second) throws IllegalArgumentException {
        if (second < 0 | second > 59) {
            throw new IllegalArgumentException("invalid time");
        }
        this.second = second;
    }

    public String toString() {
        return this.getHour() + ":" + this.getMinute() + ":" + this.getSecond();
    }
}
