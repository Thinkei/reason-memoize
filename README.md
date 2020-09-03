# re-memoize

ReasonML simple memoization utility


## Install

```
npm install --save re-memoize
```

Add `@ehrocks/re-memoize` to `bs-dependencies` in `bsconfig.json`

## Usage

```reason
let expensiveFn = () => 1;
let execOnce = Memoize.memoize0(expensiveFn);

execOnce(); /* New */
execOnce(); /* Memoized */
```

```reason
let add1 = x => x + 1;
let memoizedAdd1 = Memoize.memoize1(add1);

memoizedAdd1(10); /* New */
memoizedAdd1(10); /* Memoized */
```

```reason
let plus = (x, y) => x + y;
let memoizedPlus = Memoize.memoize2(plus);

memoizedPlus(10, 20); /* New */
memoizedPlus(10, 20); /* Memoized */
```

# 🐪 Employment Hero ReasonML adventurer group

![6569.jpg](https://assets-natgeotv.fnghub.com/POD/6569.jpg)

* We are exploring the potential of ReasonML and its application practically for Employment Hero R&D projects
* Exposure ourselves to FP paradigm
* An early attempt to build core members for the first ReasonML community in Saigon/VN
