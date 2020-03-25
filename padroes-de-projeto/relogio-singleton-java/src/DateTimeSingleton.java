import java.time.LocalDateTime;

public class DateTimeSingleton {

    public static DateTimeSingleton instance;

    private DateTimeSingleton() {}

    public static DateTimeSingleton getInstance() {
        if (instance == null) {
            instance = new DateTimeSingleton();
        }
        return instance;
    }

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
