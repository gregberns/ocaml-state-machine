let handle =
    (
      mailboxAddress: Domain.Mail.MailboxAddress.t,
      idService: Services.IdGenerationService.t,
    ) => {
  // {idService} as dependencies: StateMachine.Dependencies.t,
  // _state: Domain.State.t,

  // TODO - CHECK IF ACTOR EXISTS
  // state

  // Generate new actor ID and tokens
  let actor_id = idService.generateActorId();
  let identityToken = idService.generateMailboxVerificationToken();
  let mailboxVerificationToken = idService.generateIdentityToken();

  let actor: Domain.Actor.t = {
    id: actor_id,
    actor_type: Domain.ActorType.General,
    mailbox_address: mailboxAddress,
    mailbox_verification: UnverifiedMailbox,
    mailbox_verification_token: Some(mailboxVerificationToken),
    identity_token: identityToken,
    session_token: None,
  };

  let stateMods: list(StateMutation.t) = [
    NewActor(actor),
    NewMailbox(mailboxAddress),
    NewTask(
      SendMessage({
        to_: mailboxAddress,
        from: AdminMailer,
        expected_response: Actionable(VerifyMailbox),
      }),
    ),
  ];

  Transform.Transform(stateMods, []);
};

let handleCommand =
    (
      mailboxAddress: Domain.Mail.MailboxAddress.t,
      {idService}: Services.Dependencies.t,
      _state: Domain.State.t,
    )
    : Transform.t =>
  handle(mailboxAddress, idService);
