/// Process a command and return a response
let process_command =
    (
      _command_processor,
      _dependencies: Dependencies.t,
      _state: State.t,
      _commands: Command.t('command),
    )
    : unit => {
  ()// Process
    // let mutation_commands: StateMutation.t =
    //   command_processor.transform(dependencies, actor, commands, state);
    //
    // (state, events)
    ; // Enqueue??
 // => (CommandResponse.t, State.t, list(Event.t))
    // let _ = state_processor.transform(mutation_commands, state, ());
};
