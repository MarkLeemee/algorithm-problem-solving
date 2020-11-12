Q
 - 두 개의 객체를 입력받아 이 두 객체가 동일한 데이터를 담고 있는지 확인합니다.

 - 객체의 속성은 object literal, number, string, boolean, undefined, null 중 하나입니다.

 - 키와 속성이 전부 일치한 경우에만 true를 리턴합니다.

 

A
 - 각 객체의 길이가 갖다는 전제하에 조건문을 주어 풀어나갔습니다. 객체 안에 객체가 존재할 수 있기에 조건문 안에서는 재귀호출을 돌렸습니다. 재귀호출 되어 돌아온 값이 참이라 하여도 현재 for문이 객체의 마지막 키값이 아니면 계속 for문이 구현되어야 합니다. 해당 부분은 cnt 변수를 활용하여 for문이 돌아가는 키값을 카운트하여 구현하였습니다.

```js
const deepEquals = function (obj1, obj2) {
  if(Object.keys(obj1).length !== Object.keys(obj2).length) {
    return false;
  }
  let cnt = 0;
  for(let key1 in obj1) {
    if(typeof obj1[key1] === 'object') {
      const tempResult = deepEquals(obj1[key1], obj2[key1]);
      if(!tempResult) {
        return false;
      } else if(cnt === Object.keys(obj1).length -1) {
        return true;
      }
    } else if(obj1[key1] !== obj2[key1]) {
      return false;
    }
    cnt++;
  }
  return true;
};
 ```

 - 위의 지저분한 코드를 깔끔하게 정리해놓은 코드입니다. 원리는 간단합니다. primitive type과 object type 2가지 경우로 나눠서 재귀호출을 돌린 형태입니다. 단순히 단계단계 문제를 해결해나가는 것도 방법이지만, 애초에 큰 틀에서 설계를 하고 생각한다면 보다 깔끔한 코드가 나올 수 있습니다.

```js
const deepEquals = function (obj1, obj2) {
  if (typeof obj1 !== 'object' || typeof obj2 !== 'object') {
    return obj1 === obj2;
  }

  const obj1Keys = Object.keys(obj1);
  const obj2Keys = Object.keys(obj2);
  if (obj1Keys.length !== obj2Keys.length) {
    return false;
  }

  return obj1Keys.every((key) => deepEquals(obj1[key], obj2[key]));
};
```