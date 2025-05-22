type t('state) =
  | NoOpState
  | MutateState(list(Mutate.t('state)), list(Event.t));
