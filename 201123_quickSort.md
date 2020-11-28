Q
 - 정렬되지 않은 1차원 배열을 퀵 정렬로 정렬하시오.

 

A
 - 퀵 정렬 구현하는 문제입니다. 퀵 정렬은 특정 요소(pivot)와 타 요소들을 비교하여 큰 쪽과 작은 쪽으로 집단을 분류하며 좁혀가는 방식입니다. 이렇게 나눠진 집단을 같은 방법으로 최하위 단위(요소가 1개인 집단이 될 때까지)까지 분류하여 정렬을 완성시킵니다. 자세한 로직은 별도 알고리즘 포스팅으로 다뤄보겠습니다.

 - 이하 로직에서는 특정 값을 pivot, 작은 집단을 left, 큰 집단을 right라 설정하고 배열의 요소가 1개가 될 때까지 재귀호출을 활용하여 구현하였습니다.

```js
const quickSort = function (arr, callback = item => item) {
  if (arr.length < 2) {
    return arr;
  }

  const pivot = arr[0];
  const left = [];
  const right = [];
  for (let i = 1; i < arr.length; i++) {
    if (callback(arr[i]) <= callback(pivot)) {
      left.push(arr[i]);
    } else if (callback(arr[i]) > callback(pivot)) {
      right.push(arr[i]);
    }
  }

  return [...quickSort(left), pivot, ...quickSort(right)];
};
```

 - 이상과 같은 방법은 안정적이지만 메모리를 많이 차지한다는 단점이 있습니다. 그렇기에 퀵 정렬 함수 인자로 left값과 right값을 설정하여, 해당 배열 안에서 직접적으로 스왑하는 방법이 있습니다. 하지만 스왑하는 과정에서 중복값의 위치가 바뀔 수 있는 unstable한 정렬 방법이기도 합니다.

```js
const quickSort = function (arr, left = 0, right = arr.length - 1) {
  if (left >= right) {
    return;
  }

  const mid = Math.floor((left + right) / 2);
  const pivot = arr[mid];
  const partition = divide(arr, left, right, pivot);

  quickSort(arr, left, partition - 1);
  quickSort(arr, partition, right);

  function divide (arr, left, right, pivot) {
    while (left <= right) {
      while (arr[left] < pivot) {
        left++;
      }
      while (arr[right] > pivot) {
        right--;
      }
      if (left <= right) {
        let swap = arr[left];
        arr[left] = arr[right];
        arr[right] = swap;
        left++;
        right--;
      }
    }
    return left;
  }
  return arr;
};
```
