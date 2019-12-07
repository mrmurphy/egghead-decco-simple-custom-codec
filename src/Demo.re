module DateAsFloat = {
  let t_decode = json => {
    Decco.floatFromJson(json)->Belt.Result.map(Js.Date.fromFloat);
  };
  let t_encode = date => Js.Date.getTime(date);

  type t = Js.Date.t;
};

[@decco]
type data = {date: DateAsFloat.t};

let go = () => {
  let json = Data.data;
  Js.log2("Json", json);
  Js.log2("Data", data_decode(json));
  Js.log2("Json again", data_encode({date: Js.Date.make()}));
};

go();