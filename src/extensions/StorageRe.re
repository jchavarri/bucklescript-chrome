module type StorageArea = {
  /* chrome.storage.get */
  let get: (string, Js.Dict.t(Js.Json.tagged_t) => unit) => unit;
  let getMany: (array(string), Js.Dict.t(Js.Json.tagged_t) => unit) => unit;
  /* chrome.storage.set */
  let set: (Js.Dict.t(Js.Json.t), unit => unit) => unit;
  /* chrome.storage.remove */
  let remove: (string, unit => unit) => unit;
  let removeMany: (array(string), unit => unit) => unit;
  /* chrome.storage.clear */
  let clear: (unit => unit) => unit;
};

module Local: StorageArea = {
  [@bs.scope ("chrome", "storage", "local")] [@bs.val]
  external get : (string, [@bs] (Js.Dict.t(Js.Json.t) => unit)) => unit =
    "";
  let get: (string, Js.Dict.t(Js.Json.tagged_t) => unit) => unit =
    (str, f) =>
      get(str, [@bs] ((dict) => f(Js.Dict.map([@bs] ((v) => Js.Json.classify(v)), dict))));
  [@bs.scope ("chrome", "storage", "local")] [@bs.val]
  external getMany : (array(string), [@bs] (Js.Dict.t(Js.Json.t) => unit)) => unit =
    "get";
  let getMany: (array(string), Js.Dict.t(Js.Json.tagged_t) => unit) => unit =
    (arr, f) =>
      getMany(arr, [@bs] ((dict) => f(Js.Dict.map([@bs] ((v) => Js.Json.classify(v)), dict))));
  [@bs.scope ("chrome", "storage", "local")] [@bs.val]
  external set : (Js.Dict.t(Js.Json.t), unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "local")] [@bs.val]
  external remove : (string, unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "local")] [@bs.val]
  external removeMany : (array(string), unit => unit) => unit =
    "get";
  [@bs.scope ("chrome", "storage", "local")] [@bs.val] external clear : (unit => unit) => unit =
    "";
};

module Managed: StorageArea = {
  [@bs.scope ("chrome", "storage", "managed")] [@bs.val]
  external get : (string, [@bs] (Js.Dict.t(Js.Json.t) => unit)) => unit =
    "";
  let get: (string, Js.Dict.t(Js.Json.tagged_t) => unit) => unit =
    (str, f) =>
      get(str, [@bs] ((dict) => f(Js.Dict.map([@bs] ((v) => Js.Json.classify(v)), dict))));
  [@bs.scope ("chrome", "storage", "managed")] [@bs.val]
  external getMany : (array(string), [@bs] (Js.Dict.t(Js.Json.t) => unit)) => unit =
    "get";
  let getMany: (array(string), Js.Dict.t(Js.Json.tagged_t) => unit) => unit =
    (arr, f) =>
      getMany(arr, [@bs] ((dict) => f(Js.Dict.map([@bs] ((v) => Js.Json.classify(v)), dict))));
  [@bs.scope ("chrome", "storage", "managed")] [@bs.val]
  external set : (Js.Dict.t(Js.Json.t), unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "managed")] [@bs.val]
  external remove : (string, unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "managed")] [@bs.val]
  external removeMany : (array(string), unit => unit) => unit =
    "get";
  [@bs.scope ("chrome", "storage", "managed")] [@bs.val] external clear : (unit => unit) => unit =
    "";
};

module Sync: StorageArea = {
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val]
  external get : (string, [@bs] (Js.Dict.t(Js.Json.t) => unit)) => unit =
    "";
  let get: (string, Js.Dict.t(Js.Json.tagged_t) => unit) => unit =
    (str, f) =>
      get(str, [@bs] ((dict) => f(Js.Dict.map([@bs] ((v) => Js.Json.classify(v)), dict))));
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val]
  external getMany : (array(string), [@bs] (Js.Dict.t(Js.Json.t) => unit)) => unit =
    "get";
  let getMany: (array(string), Js.Dict.t(Js.Json.tagged_t) => unit) => unit =
    (arr, f) =>
      getMany(arr, [@bs] ((dict) => f(Js.Dict.map([@bs] ((v) => Js.Json.classify(v)), dict))));
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val]
  external set : (Js.Dict.t(Js.Json.t), unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val]
  external remove : (string, unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val]
  external removeMany : (array(string), unit => unit) => unit =
    "get";
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val] external clear : (unit => unit) => unit = "";
};