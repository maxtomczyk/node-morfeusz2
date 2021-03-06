const m = require('bindings')('morfeusz2')

function version () {
  return m.version()
}

function copyright () {
  return m.copyright()
}

function dictCopyright () {
  return m.dictCopyright()
}

function analyze (text) {
  return m.analyze(text)
}

module.exports = {
  version,
  copyright,
  dictCopyright,
  analyze
}
