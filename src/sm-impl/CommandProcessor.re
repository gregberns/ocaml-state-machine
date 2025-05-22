let transform =
    (dependencies: Services.Dependencies.t, state, _actor, command: Command.t) =>
  switch (command) {
  | RegisterActor(mailboxAddress) =>
    CommandHandler_RegisterActor.handleCommand(
      mailboxAddress,
      dependencies,
      state,
    )
  | VerifyIdentity(_actor_id, _identity_token) => NoOpState
  | VerifyMailbox(_actor_id, _session_token, _verification_token) => NoOpState
  };
