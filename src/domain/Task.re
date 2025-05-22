type t =
  | SendMessage(Mail.MailboxMessage.t)
  | VerifyIdentity(ActorId.t);
