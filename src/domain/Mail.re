module MailboxAddress = {
  type t =
    | Address(string)
    | AdminMailer;
};

/// Token for verifying mailbox addresses
module MailboxVerificationToken = {
  type t = string;
};

module MessageAction = {
  type t =
    | VerifyMailbox
    | VerifyIdentity;
};

module ExpectedResponse = {
  type t =
    | Informational
    | Actionable(MessageAction.t);
};

/// A message in a mailbox
module MailboxMessage = {
  type t = {
    to_: MailboxAddress.t,
    from: MailboxAddress.t,
    expected_response: ExpectedResponse.t,
  };
};

/// A mailbox containing messages
module Mailbox = {
  type t = {
    address: MailboxAddress.t,
    messages: list(MailboxMessage.t),
  };
  let makeEmpty = address => {
    address,
    messages: [],
  };
  let make = (address, message) => {
    address,
    messages: [message],
  };
  let add = (message, {messages, _} as mailbox) => {
    ...mailbox,
    messages: [message, ...messages],
  };
};

module Mailboxes = {
  type t = Map.t(MailboxAddress.t, Mailbox.t, MailboxAddress.t);

  let addMailbox = (address, mailboxes) =>
    Map.update(
      address,
      Option.fold(Mailbox.makeEmpty(address), id) >> Option.pure,
      mailboxes,
    );

  let addMessage = (address, message, mailboxes) =>
    Map.update(
      address,
      Option.fold(Mailbox.make(address, message), Mailbox.add(message))
      >> Option.pure,
      mailboxes,
    );
};

module MailboxVerificationStatus = {
  type t =
    | UnverifiedMailbox
    | VerifiedMailbox;
};
