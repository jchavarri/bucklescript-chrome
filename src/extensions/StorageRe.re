module type StorageArea = {
  /* chrome.storage.get */
  let get: (string, unit => unit) => unit;
  let getMany: (array(string), unit => unit) => unit;
  /* chrome.storage.set */
  let set: (Js.t({..}), unit => unit) => unit;
  /* chrome.storage.remove */
  let remove: (string, unit => unit) => unit;
  let removeMany: (array(string), unit => unit) => unit;
  /* chrome.storage.clear */
  let clear: (unit => unit) => unit;
};

module Local: StorageArea = {
  [@bs.scope ("chrome", "storage", "local")] [@bs.val]
  external set : (Js.t({..}), unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "local")] [@bs.val]
  external get : (string, unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "local")] [@bs.val]
  external getMany : (array(string), unit => unit) => unit =
    "get";
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
  external set : (Js.t({..}), unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "managed")] [@bs.val]
  external get : (string, unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "managed")] [@bs.val]
  external getMany : (array(string), unit => unit) => unit =
    "get";
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
  external set : (Js.t({..}), unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val]
  external get : (string, unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val]
  external getMany : (array(string), unit => unit) => unit =
    "get";
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val]
  external remove : (string, unit => unit) => unit =
    "";
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val]
  external removeMany : (array(string), unit => unit) => unit =
    "get";
  [@bs.scope ("chrome", "storage", "sync")] [@bs.val] external clear : (unit => unit) => unit = "";
};