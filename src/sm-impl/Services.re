module IdGenerationService = {
  type t = {
    generateActorId: unit => Domain.ActorId.t,
    generateMailboxVerificationToken:
      unit => Domain.Mail.MailboxVerificationToken.t,
    generateIdentityToken: unit => Domain.Auth.IdentityToken.t,
  };
};

module Dependencies = {
  type t = {idService: IdGenerationService.t};
};

/// Create a simple in-memory ID generation service
/// This is a basic implementation that just uses static IDs for simplicity
let create_in_memory_id_service = (): IdGenerationService.t => {
  let generateActorId = () => {
    "actor-1";
  };

  let generateMailboxVerificationToken =
      (): Domain.Mail.MailboxVerificationToken.t => "token-1";

  let generateIdentityToken = () => "token-1";

  {
    generateActorId,
    generateMailboxVerificationToken,
    generateIdentityToken,
  };
};
