type t =
  | NoOpState
  | Transform(list(StateMutation.t), list(Event.t));
