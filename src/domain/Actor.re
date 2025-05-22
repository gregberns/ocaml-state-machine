type t = {
  id: ActorId.t,
  actor_type: ActorType.t,
  mailbox_address: Mail.MailboxAddress.t,
  mailbox_verification: Mail.MailboxVerificationStatus.t,
  mailbox_verification_token: option(Mail.MailboxVerificationToken.t),
  identity_token: Auth.IdentityToken.t,
  session_token: option(Auth.SessionToken.t),
};
