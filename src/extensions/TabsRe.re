/* https://developer.chrome.com/extensions/tabs */
/* Common types */
[@bs.deriving {jsConverter: newType}]
type tabStatus = [ [@bs.as "loading"] | `Loading [@bs.as "completed"] | `Completed];

[@bs.deriving {jsConverter: newType}]
type windowType = [
  [@bs.as "normal"] | `Normal
  [@bs.as "popup"] | `Popup
  [@bs.as "panel"] | `Panel
  [@bs.as "app"] | `App
  [@bs.as "devtools"] | `Devtools
];

[@bs.deriving {jsConverter: newType}]
type mutedInfoReason = [
  [@bs.as "user"] | `User
  [@bs.as "capture"] | `Capture
  [@bs.as "extension"] | `Extension
];

type mutedInfo = {
  .
  "muted": bool, "reason": abs_mutedInfoReason, "extensionId": Js.nullable(string)
};

type tab = {
  .
  "id": Js.nullable(int),
  "index": int,
  "windowId": int,
  "openerTabId": Js.nullable(int),
  "selected": bool,
  "highlighted": bool,
  "active": bool,
  "pinned": bool,
  "audible": Js.nullable(bool),
  "discarded": bool,
  "autoDiscardable": bool,
  "mutedInfo": Js.nullable(mutedInfo),
  "url": Js.nullable(string),
  "title": Js.nullable(string),
  "favIconUrl": Js.nullable(string),
  "status": Js.nullable(string),
  "incognito": bool,
  "width": Js.nullable(int),
  "height": Js.nullable(int),
  "sessionId": Js.nullable(string)
};

/* chrome.tabs.query */
type queryInfo;

[@bs.obj]
external mkQueryInfo :
  (
    ~active: Js.boolean=?,
    ~pinned: Js.boolean=?,
    ~audible: Js.boolean=?,
    ~muted: Js.boolean=?,
    ~highlighted: Js.boolean=?,
    ~discarded: Js.boolean=?,
    ~autoDiscardable: Js.boolean=?,
    ~currentWindow: Js.boolean=?,
    ~status: abs_tabStatus=?,
    ~url: array(string)=?, /* TODO: Support passing a string in `url` as well */
    ~windowId: int=?,
    ~windowType: abs_windowType=?,
    ~index: int=?,
    unit
  ) =>
  queryInfo =
  "";

[@bs.scope ("chrome", "tabs")] [@bs.val] external query : (queryInfo, array(tab) => unit) => unit =
  "";

/* chrome.tabs.executeScript */
type scriptDetails;

[@bs.obj]
external mkScriptDetails :
  (
    ~code: string=?,
    ~file: string=?,
    ~allFrames: Js.boolean=?,
    ~frameId: int=?,
    ~matchAboutBlank: Js.boolean=?,
    ~runAt: Js.boolean=?,
    unit
  ) =>
  scriptDetails =
  "";

[@bs.scope ("chrome", "tabs")] [@bs.val] external executeScript : (scriptDetails => unit) => unit =
  "";

[@bs.scope ("chrome", "tabs")] [@bs.val]
external executeScriptWithTabId :
  (int, scriptDetails, Js.nullable(array(Js.t('a))) => unit) => unit =
  "executeScript";

[@bs.scope ("chrome", "tabs")] [@bs.val]
external executeScriptWithCallback : (scriptDetails, array(Js.t('a)) => unit) => unit =
  "executeScript";

[@bs.scope ("chrome", "tabs")] [@bs.val]
external executeScriptWithTabIdAndCallback : (int, scriptDetails, array(Js.t('a)) => unit) => unit =
  "executeScript";