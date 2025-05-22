type t =
  | NewActor(Domain.Actor.t)
  | NewMailbox(Domain.Mail.MailboxAddress.t)
  | NewTask(Domain.Task.t);

// /// Response to a command
// pub type StateMutations {
//   RegisterResponse(actor_id: actor.ActorId, identity_token: auth.IdentityToken)
//   VerifyIdentityResponse(session_token: auth.SessionToken)
//   VerifyMailboxResponse
//   ErrorResponse(message: String)
// }
