let update_state =
    (
      {actors, mailboxes, _} as state: Domain.State.t,
      action: Domain.StateAction.t,
    ) =>
  switch (action) {
  | Domain.StateAction.UpsertActor(actor_id, actor) => {
      ...state,
      actors:
        Map.update(
          actor_id,
          Option.fold(actor, _existing_actor => actor) >> Option.pure,
          actors,
        ),
    }
  | CreateMailbox(address) => {
      ...state,
      mailboxes: Domain.Mail.Mailboxes.addMailbox(address, mailboxes),
    }
  | AddMailboxMesage(address, message) => {
      ...state,
      mailboxes:
        Domain.Mail.Mailboxes.addMessage(address, message, mailboxes),
    }
  };

// Update state
// let new_actors = dict.insert(state.actors, actor_id, actor)
// let new_mailboxes = dict.insert(state.mailboxes, mailbox_address, mailbox)
// let new_tasks = [task, ..state.tasks]

// let new_state =
//   State(actors: new_actors, mailboxes: new_mailboxes, tasks: new_tasks)
