project('cs330-project', 'c', default_options: ['b_coverage=true'])

lib_sources = ['security-device.c', 'security-device.h', 'util.c', 'util.h']

main = executable('main', 'main.c', lib_sources)
stats = executable('stats', 'stats.c', lib_sources)

test_util_sources = lib_sources + ['test/test_utils.c', 'test/test_utils.h']

test_fsm_access = executable('test_fsm_access', 'test/test_fsm_access.c', test_util_sources)
test('Test fsm.state.access_state', test_fsm_access)

test_fsm_action = executable('test_fsm_action', 'test/test_fsm_action.c', test_util_sources)
test('Test fsm_transition unlock/lock', test_fsm_action)

test_fsm_init = executable('test_fsm_init', 'test/test_fsm_init.c', test_util_sources)
test('Test fsm_init', test_fsm_init)

test_weot = executable('test_weot', 'test/test_weot.c', test_util_sources)
test('Test fsm_transition terminate', test_weot)

test_fsm_repeat = executable('test_fsm_repeat', 'test/test_fsm_repeat.c', test_util_sources)
test('Test repeat 1', test_fsm_repeat)

test_fsm_repeat2 = executable('test_fsm_repeat2', 'test/test_fsm_repeat2.c', test_util_sources)
test('Test repeat 2', test_fsm_repeat2)