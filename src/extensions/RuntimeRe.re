/* https://developer.chrome.com/extensions/runtime */

/* Warning: this module belongs to extensions, but it's exposed as a direct
property of `chrome` */

[@bs.scope ("chrome", "runtime")] [@bs.val] external lastError : Js.nullable(Js.t({..})) =
"";