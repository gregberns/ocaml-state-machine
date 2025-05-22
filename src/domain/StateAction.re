type t =
  | UpsertActor(ActorId.t, Actor.t)
  | CreateMailbox(Mail.MailboxAddress.t)
  // | SendMessage(Mail.MailboxAddress.t, Mail.MailboxMessage.t)
  | AddMailboxMesage(Mail.MailboxAddress.t, Mail.MailboxMessage.t);
