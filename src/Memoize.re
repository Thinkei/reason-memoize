type last('a, 'b) = {
  params: 'a,
  res: 'b,
};

let diffInLength = (x, y) => Array.length(x) != Array.length(y);

let diffInElement = (x, y) => {
  let i = ref(0);
  let n = Array.length(x);
  let diff = ref(false);

  while (! diff^ && i^ < n) {
    if (x[i^] != y[i^]) {
      diff := true;
    };
    i := i^ + 1;
  };

  diff^;
};

let memoize = fn => {
  let last = ref(None);
  params => {
    switch (last.contents) {
    | None =>
      let newRes = fn(params);
      let newLast = {params, res: newRes};
      last := Some(newLast);
      newRes;
    | Some(contents) =>
      if (diffInLength(contents.params, params) || diffInElement(contents.params, params)) {
        let newRes = fn(params);
        let newLast = {params, res: newRes};
        last := Some(newLast);
        newRes;
      } else {
        contents.res;
      }
    };
  };
};

let memoize1 = fn => {
  let fn1 = x => fn(x[0]);
  x => memoize(fn1)([|x|])
};

let memoize2 = fn => {
  let fn2 = x => fn(x[0], x[1]);
  (x, y) => memoize(fn2)([|x, y|])
};

let memoize3 = fn => {
  let fn3 = x => fn(x[0], x[1], x[2]);
  (x, y, z) => memoize(fn3)([|x, y, z|])
};

let memoize4 = fn => {
  let fn4 = x => fn(x[0], x[1], x[2], x[3]);
  (x, y, z, a) => memoize(fn4)([|x, y, z, a|])
};