/// Events generated during command processing
type t =
  | NewTaskAdded(string)
  | MailboxVerified(Domain.ActorId.t);
