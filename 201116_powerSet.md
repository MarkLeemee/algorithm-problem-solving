Q
 - 오름차순 정렬된 배열에서 target 인덱스를 찾으시오.

 - 탐색속도는 O(log n)으로 하면서, target이 없을 시에는 -1을 리턴합니다.

 

A
 - 배열이 오름차순으로 정렬되어 있기에 이진트리탐색(O(log n))으로 쉽게 풀 수 있는 문제입니다. 원리는 탐색 구역의 시작과 끝을 정하고, 그 중간값과 비교하면서 탐색 구역을 좁혀나가는 방식입니다. 

```js
const binarySearch = function (arr, target) {
  let front = 0;
  let end = arr.length - 1;
  let mid = Math.floor((front + end) / 2);
  while (arr[mid] !== target) {
    if(front > end) {
      return -1;
    }
    if(arr[mid] < target) {
      front = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = Math.floor((front + end) / 2);
  }
  return mid;
};
```

 - 위의 풀이와 원리는 같지만, while문의 조건을 반대로 넣어준 경우입니다.

```js
const binarySearch = function (arr, target) {
  let left = 0,
    right = arr.length - 1;
  while (left <= right) {
    let middle = parseInt((right + left) / 2);
    if (arr[middle] === target) {
      return middle;
    }
    if (target < arr[middle]) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
};
```