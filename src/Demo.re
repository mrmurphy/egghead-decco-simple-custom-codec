module DateAsFloat = {
  let t_decode = json => {
    Decco.floatFromJson(json)->Belt.Result.map(Js.Date.fromFloat);
  };
  let t_encode = date => Js.Date.getTime(date)->Decco.floatToJson;

  type t = Js.Date.t;
};

[@decco]
type data = {date: DateAsFloat.t};

let go = () => {
  let json = Data.data;
  Js.log2("Json", json);
  switch (data_decode(json)) {
  | Ok(data) => Js.log2("data", data)
  | Error(msg) => Js.log2("failed", msg)
  };
  Js.log2("Data", data_decode(json));
  Js.log2("Json again", data_encode({date: Js.Date.make()}));
};

go();