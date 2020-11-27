Q
 - 비동기 함수들을 요소로 갖는 배열(tasks)과 함수(final)를 입력받아 아래와 같은 동작을 하는 함수를 구현하시오.

  * 비동기 함수들을 차례대로 실행하고, 비동기 함수의 콜백함수에 전달되는 인자를 비동기 함수의 실행 순서대로 저장합니다.

  * 모든 결과가 저장되면, 전체 결과를 final 함수에 적용합니다. (결과 배열을 인자로 받습니다.)

 - tasks의 각 비동기 함수들은 엄밀한 의미에서 비동기 함수는 아니며, 비동기 오퍼레이션을 포함하고 있는 함수입니다.

  - final은 입력으로 주어지므로 출력의 형태는 신경쓰지 않아도 됩니다.

  - tasks의 각 비동기 함수들은 콜백함수를 인자로 받아, 비동기 오퍼레이션이 완료될 때 호출합니다.

 - final 함수는 tasks의 각 비동기 함수의 콜백에 전달된 결과들을 비동기 함수의 실행 순서대로 담은 배열을 인자로 받아 실행되어야 합니다.

 - 비동기 함수들의 실행 순서와 완료 순서는 서로 다를 수 있습니다.

 - Promise.all, async/await 등의 비동기 관련 메서드는 사용은 금지됩니다.

 - 입출력 예시

```js
asyncMap(
  [
    function (cb) {
      setTimeout(function () {
        cb('one');
      }, 200);
    },
    function (cb) {
      setTimeout(function () {
        cb('two');
      }, 100);
    },
  ],
  function (results) {
    console.log(results); // --> ['one', 'two']
  }
);
```

A
 - 알고리즘 문제라기 보다는 JS 비동기 호출과 클로저 개념을 묻는 문제입니다. 즉, 비동기 오퍼레이션을 동기 순서대로 결과를 담는 것이 목적입니다. 그러기 위해서 클로저 개념을 활용하여 인덱스를 묶어버리는 방식을 활용하였습니다. 결국 비동기 오퍼레이션이 언제 호출되어 언제 작업이 완료되든, results의 인덱스 값은 동기순으로 묶어버리기에 promise.all과 같은 결과를 만들어 낼 수 있었습니다.

```js
const asyncMap = function (tasks, final) {
  var counter = 0;
  var results = [];
  
  function callbackClosure(index) {
    return function callback(callbackValue) {
      counter++;
      results[index] = callbackValue;

      if (counter === tasks.length) {
        final(results);
      }
    };
  }
  
  if (counter === tasks.length) {
    final(results);
    return;
  }
  
  tasks.forEach((item, index) => {
    item(callbackClosure(index));
  });
};
```
