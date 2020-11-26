Q
 - 임의의 tree를 구성하는 루트 노드(root node) 입력받아 리프 노드(leaf node)의 개수를 리턴하시오.

 

A
 - 리프 노드라하면 더 이상 자식을 갖지 않는 최하위 노드를 의미합니다. DFS 전체탐색을 하면서 더 이상 자식노드가 없을 시에는 cnt를 카운트 해주는 방식으로 손쉽게 구할 수 있습니다.

```js
let countLeaves = function (root) {
  var cnt = cnt ? cnt : 0;
  if(root.children.length > 0) {
    for(let el of root.children) {
      cnt += countLeaves(el);
    }
  } else {
    cnt++;
  }
  return cnt;
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
