public static void selectionSort(ArrayList<String> arr) {
    int n = arr.size();
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min = i;

        for (j = i + 1; j < n; j++) {                                             //Agafa la posició de l'array amb l'ordre alfabètic següent (A-Z)
            if (arr.get(j).compareTo(arr.get(min)) < 0) {                         //Compara l'ordre alfabètic dels caràcters
                min = j;
            }
        }

        String temp = arr.get(min);                                             //Swap(arr[min],arr[i])
        arr.set(min, arr.get(i));
        arr.set(i, temp);
    }

    for (String s : arr) {                                                       //Mostra les tasques ordenades alfabeticament
        System.out.println(s);
    }
}