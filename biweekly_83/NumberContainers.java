import java.util.*;


class RunSolution {
    public static void main(String[] args) {
        NumberContainers solution = new NumberContainers();

        System.out.println(solution.find(10));
        System.out.println(solution.find(10));

        solution.change(2, 10);
        solution.change(1, 10);
        solution.change(3, 10);
        solution.change(5, 10);

        System.out.println(solution.find(10));

        solution.change(1, 20);

        System.out.println(solution.find(10));
    }
}

class NumberContainers {
    Map<Integer, Integer> indexMap;

    public NumberContainers() {
        indexMap = new TreeMap<>();
    }

    public void change(int index, int number) {
        indexMap.put(index, number);
    }

    public int find(int number) {
        for (Map.Entry<Integer, Integer> entry : indexMap.entrySet()) {
            if (entry.getValue() == number) {
                return entry.getKey();
            }
        }
        return -1;
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */
