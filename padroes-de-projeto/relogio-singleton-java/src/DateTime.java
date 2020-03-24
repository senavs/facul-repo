import java.time.LocalDateTime;

public class DateTime {

    private LocalDateTime now() {
        return LocalDateTime.now();
    }

    public Date getDate() {
        LocalDateTime now = this.now();
        return new Date(now.getDayOfMonth(), now.getMonthValue(), now.getYear());
    }

    public Time getTime() {
        LocalDateTime now = this.now();
        return new Time(now.getHour(), now.getMinute(), now.getSecond());
    }

    public String toString() {
        return this.getDate() + " " + this.getTime();
    }
}
