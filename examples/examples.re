open Chrome.Apps.Identity;

let testGetAuthToken = () =>
  getAuthToken(
    mkAuthOptions(
      ~interactive=true,
      (),
      ~scopes=["scope"],
      ~account=mkAccountInfo(~id="id", ())
    ),
    (v) => Js.log(v)
  );

let testGetProfileUserInfo = getProfileUserInfo((userInfo) => Js.log(userInfo##email));

let testRemoveCachedAuthToken = removeCachedAuthToken({"token": "token"}, () => Js.log("Success"));

let testLaunchWebAuthFlow =
  launchWebAuthFlow(
    mkWebFlowOptions(~url="https://example.com", ()),
    (mResponseURL, ()) =>
      switch (Js.Null.toOption(mResponseURL)) {
      | Some(responseUrl) => Js.log(responseUrl)
      | None => Js.log("No url returned!")
      }
  );

let testGetRedirectURL = getRedirectURL(Js.Null.fromOption(Some("path")));

let testOnSignInChanged =
  OnSignInChanged.addListener(
    (accountInfo, signedIn) => Js.log(signedIn) |> ((_) => Js.log(accountInfo##id))
  );
