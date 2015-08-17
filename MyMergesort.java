import java.io.*;


 class MyMergesort {

    int[] array;
    int[] tempMergArr;
    int length;

    public static void main(String a[]){

        int[] inputArr = {45,23,11,89,77,98,4,28,65,43};
        MyMergesort mms = new MyMergesort();
        mms.sort(inputArr);
        for(int i:inputArr){
            System.out.print(i);
            System.out.print(" ");
        }
    }

     void sort(int inputArr[]) {
        this.array = inputArr;
        this.length = inputArr.length;
        this.tempMergArr = new int[length];
        doMergeSort(0, length - 1);
    }

     void doMergeSort(int beg, int end) {

        if (beg <end) {
            int middle = beg + (end-beg) / 2;
           
            doMergeSort(beg, middle);
          
            doMergeSort(middle + 1, end);
            
            mergeParts(beg, middle, end);
        }
    }

     void mergeParts(int beg, int middle, int end) {

        for (int i = beg; i <= end; i++) {
            tempMergArr[i] = array[i];
        }
        int i = beg;
        int j = middle + 1;
        int k = beg;
        while (i <= middle && j <= end) {
            if (tempMergArr[i] <= tempMergArr[j]) {
                array[k] = tempMergArr[i];
                i++;
            } else {
                array[k] = tempMergArr[j];
                j++;
            }
            k++;
        }
        while (i <= middle) {
            array[k] = tempMergArr[i];
            k++;
            i++;
        }

    }
}

