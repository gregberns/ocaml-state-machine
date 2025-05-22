type t = {
  actors: Map.t(ActorId.t, Actor.t, ActorId.t),
  mailboxes: Mail.Mailboxes.t,
  tasks: list(Task.t),
};
