type t =
  | RegisterActor(Domain.Mail.MailboxAddress.t)
  | VerifyIdentity(Domain.ActorId.t, Domain.Auth.IdentityToken.t)
  | VerifyMailbox(
      Domain.ActorId.t,
      Domain.Auth.SessionToken.t,
      Domain.Mail.MailboxVerificationToken.t,
    );
/// Registers a new Actor in the system
