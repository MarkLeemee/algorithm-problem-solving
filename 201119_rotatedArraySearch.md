Q
 - 부분적으로 오름차순된 배열에서 타겟의 인덱스를 리턴하시오.

 - 부분적으로 오름차순된 배열이란, [ 5, 6, 7, 1, 2, 3, 4 ] 와 같이 좌 혹은 우로 일정칸을 움직이면 정렬되어지는 배열입니다.

 - 중복되는 요소는 없으며, 타겟이 없을 시에는 -1을 리턴합니다.

 - 전체 탐색(O(n))이 아닌 부분탐색 (O(log n)) 속도로 탐색하시오.

 

A
 - 부분적이긴 하지만 정렬이 되었다는 특징을 가진 배열입니다. 즉, 기준점을 달리 생각하면 정렬된 배열임으로 이진트리탐색 O(log n) 속도로 탐색 할 수 있습니다.

 - 배열의 min, mid, max점을 잡고 mid를 기준으로 min ~ mid가 정렬된 상태인지 mid ~ max가 상태인지 2가지로 구분지어서 생각하면 됩니다. 해당 기준으로 target과 비교하여 위치를 찾아 간다면(정렬된 상태 구역으로 들어가니깐) 바로 이진트리탐색 형태로 만들어집니다. 

 - 이후에는 이진트리탐색과 동일하게 while문으로 target값을 찾아나가면 됩니다.

```js
const rotatedArraySearch = function (rotated, target) {
  let minInd = 0;
  let maxInd = rotated.length-1;
  while (minInd <= maxInd) {
    let midInd = Math.floor((minInd+maxInd)/2);
    if(target === rotated[midInd]){
      return midInd;
    }
    
    // mid가 max보다 작다는 것은 오른쪽이(mid ~ max)는 정렬된 상태라는 것
    if(rotated[midInd] <= rotated[maxInd]){
      // target이 mid보다 작다는 것은 or max보다 크다는 것은
      // target이 mid 좌측에 존재한다는 것
      // ==> mid ~ max 사이는 정렬된 상태니깐!!
      if(target < rotated[midInd] || target > rotated[maxInd]){
         maxInd = midInd - 1;
         
         // 2가지 경우에 해당되지 않으면 mid보다 크거나 max보다 작은거니깐 mid ~ max 사이
         // 즉, min이 mid ~ max로 가야한다.
       } else {
         minInd = midInd + 1; 
       }
       
      // mid가 min보다 크다는 것은 왼쪽이(min ~ mid)가 정렬된 상태라는 것
    } else if(rotated[midInd] >= rotated[minInd] ) {
      // target이 mid보다 크다는 것은 or max보다 작다는 것은
      // target이 mid 우측에 존재한다는 것
      // ==> min ~ mid 사이는 정렬된 상태니깐!!
      if(target > rotated[midInd] || target < rotated[minInd]){
        minInd = midInd + 1;
        
        // 2가지 경우에 해당되지 않으면 mid보다 작거나 min보다 큰거니깐 min ~ mid 사이
        // 즉, max가 min ~ mid로 가야한다.
      } else {
        maxInd = midInd - 1; 
      }
    }
  } 
  return -1;
}
```
