/* https://developer.chrome.com/extensions/api_index */
module Tabs = TabsRe;
module Storage = StorageRe;

[@bs.scope ("chrome", "runtime")] [@bs.val] external lastError : Js.nullable(Js.t({..})) =
"";