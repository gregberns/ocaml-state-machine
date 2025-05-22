module type Context = {
  type dependencies;

  type t = {
    dependencies,
    // State.t,
  };
};

// module type CommandProcessor = {
//   let transform: ((module Context), State.t, Actor.t, Command.t) => unit;
// };
