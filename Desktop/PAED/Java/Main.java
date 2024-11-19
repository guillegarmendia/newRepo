import java.util.ArrayList;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String filename = "descending.txt";
        ArrayList<String> arr = new ArrayList<>();
        boolean numRead = false;

        try (Scanner scanner = new Scanner(new File(filename))) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                if(!numRead) {
                    numRead = true;
                } else {
                    arr.add(line);
                }
            }
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + e.getMessage());
        }


        selectionSort(arr);

        for(String s : arr) {
            System.out.println(s);
        }

    }

    public static void selectionSort(ArrayList<String> arr) {
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            int min = i;

            for (int j = i + 1; j < n; j++) {
                if (arr.get(j).compareTo(arr.get(min))<0) {                         //If difference of value of the characters is negative, it has to sort
                    min = j;
                }
            }

                String temp = arr.get(min);
                arr.set(min,arr.get(i));
                arr.set(i,temp);
        }
    }
}
