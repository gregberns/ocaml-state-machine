type t =
  | AnonAuth
  | ActorIdAuth(ActorId.t)
  | ActorAuth(Actor.t);
