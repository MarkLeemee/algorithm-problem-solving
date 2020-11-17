Q
 - Tree BFS 탐색하여 탐색 순으로 값을 반환하시오. (배열 타입으로)

 - 자식과 부모만 연결된 기본 트리 모형으로 별도의 중복 확인 처리는 하지 않아도 무방합니다.

 

A
 - BFS는 queue 자료구조를 활용하면 손쉽게 구현할 수 있습니다. 즉, 현 노드의 자식들을 queue에 순차적으로 넣고, queue에 들어간 순으로 처리해주면 BFS탐색이 됩니다. 즉, 현재 노드의 자식들을 지금 queue에 넣어도, 이전에 넣었던 형제 노드들의 작업이 처리가 되지 않았다면, 형제 노드들 먼저 처리가 되는 로직입니다.

```js
let bfs = function (node) {
  let currentNode = node;
  let queue = [];
  let result = [];
  queue.push(currentNode);
  while (queue.length > 0) {
   currentNode = queue.shift();
   result.push(currentNode.value);
     for(let i = 0; i < currentNode.children.length; i++) {
       queue.push(currentNode.children[i]);
     }
  }
  return result;
};

let Node = function (value) {
  this.value = value;
  this.children = [];
};

Node.prototype.addChild = function (child) {
  this.children.push(child);
  return child;
};
```

 - 같은 로직이지만 slice와 forEach를 활용하여 작성해보았습니다.

```js
let bfs = function (node) {
  let queue = [node];
  const values = [];
  while (queue.length > 0) {
    const head = queue[0];
    queue = queue.slice(1);
    values.push(head.value);
    head.children.forEach((child) => queue.push(child));
  }
  return values;
};
```
