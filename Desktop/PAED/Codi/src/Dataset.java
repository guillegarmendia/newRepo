import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Dataset {
    private String task;
    private  LocalDate date;
    private int time;
    private int difficulty;
    private int progress;
    private String colorCode;
    private String building;

    public Dataset(String task, LocalDate date, int time, int difficulty, int progress, String colorCode, String building) {             //Constructor
        this.task = task;
        this.date = date;
        this.time = time;
        this.difficulty = difficulty;
        this.progress = progress;
        this.colorCode = colorCode;
        this.building = building;
    }

    public LocalDate getDate(){
        return date;

    }

    public int getTime(){
        return time;
    }

    public int getDifficulty(){
        return difficulty;
    }

    public String toString() {
        return task + ";" + date.format(DateTimeFormatter.ofPattern("d-M-yy")) + ";" + time + ";" + difficulty + ";" + colorCode + ";" + building;
    }

}
