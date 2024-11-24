public static int partition(ArrayList<Dataset> datasets, int i, int j) {

    int left = i;
    int right = j;
    int mid = (i + j) / 2;
    Dataset pivot = datasets.get(mid);                                               //Escollim el del mig com a pivot

    while (true) {
        while (compare(datasets.get(left),pivot) < 0) {
            left++;                                                                 //Passa cap a la dreta
        }

        while (compare(datasets.get(right), pivot) > 0) {
            right--;                                                               //Passa cap a l'esquerra
        }

        if (left >= right) {
            return right;                                                           //Retorna posició de right
        }


        Collections.swap(datasets,left,right);                                                //Es fa un swap
        left++;
        right--;
    }


}

public static void quickSort(ArrayList<Dataset> datasets, int i, int j) {
    if (i < j) {
        int p = partition(datasets, i, j);
        quickSort(datasets, i, p);                                           //Part de l'esquerra
        quickSort(datasets, p + 1, j);                                      //Part de la dreta
    }
}

public static int compare(Dataset d1, Dataset d2) {


    int compareDate = d1.getDate().compareTo(d2.getDate());
    if(compareDate != 0) return compareDate;

    int compareTime = Integer.compare(d1.getTime(),d2.getTime());
    if(compareTime != 0) return compareTime;

    return Integer.compare(d1.getDifficulty(),d2.getDifficulty());

}