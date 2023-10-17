import os
import re
import csv


def gen_test(v_type_list, v_ele_list, v_name_list, func_name):
    print(v_type_list)
    print(v_ele_list)
    print(v_name_list)
    test_content = '''
#else
  fputc('\\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {\n'''
    for i in range(len(v_type_list)-1):
        test_content = test_content+'    simde_'+v_type_list[i]+v_ele_list[i]+'_t '+v_name_list[i]+' = simde_test_arm_neon_random_'+v_type_list[i][0]+v_ele_list[i]+'();\n'
    test_content = test_content+'    simde_'+v_type_list[-1]+v_ele_list[-1]+'_t '+v_name_list[-1]+' = '+func_name+'('
    for i in range(len(v_name_list)-1):
        if i != len(v_name_list)-2:
            test_content = test_content+v_name_list[i]+', '
        else:
            test_content = test_content+v_name_list[i]+');\n\n'

    for i in range(len(v_name_list)):
        if i == 0:
            test_content = test_content + '    simde_test_arm_neon_write_'+v_type_list[i][0]+v_ele_list[i]+'(2, '+v_name_list[i]+', SIMDE_TEST_VEC_POS_FIRST);\n'
        elif i == len(v_name_list)-1:
            test_content = test_content + '    simde_test_arm_neon_write_'+v_type_list[i][0]+v_ele_list[i]+'(2, '+v_name_list[i]+', SIMDE_TEST_VEC_POS_LAST);\n'
        else:
            test_content = test_content + '    simde_test_arm_neon_write_'+v_type_list[i][0]+v_ele_list[i]+'(2, '+v_name_list[i]+', SIMDE_TEST_VEC_POS_MIDDLE);\n'
    test_content = test_content + '  }\n  return 1;\n#endif\n'

    return test_content


type_list = [["float16"],
             ["float32", "float"],
             ["float64", "double"],
             ["uint8"],
             ["uint16"],
             ["uint32", "unsigned int", "unsigned"],
             ["uint64"],
             ["int8"],
             ["int16"],
             ["int32", "int"],
             ["int64"]]

dic_type_list = {"float16":["float", "16"],
                 "float32":["float", "32"],}

def main_gen(file_path):
    # Open the file for reading
    with open(file_path, 'r') as file:
        lines = file.readlines()
        for i in range(len(lines)):
            if "static int" in lines[i]:
                if "#if 1" not in lines[i+2]:
                    func_name = lines[i+1][5:lines[i+1].find(' ')]
                    lines.insert(i+2, '#if 1\n')
                    print(f"line numbers: {i}, {func_name}")
                    # get input para
                    v_type_list = [] # ex. float16 or uint32
                    v_ele_list = [] # ex. 32x2
                    v_name_list = [] # ex. a
                    for j in range(i, i+1000, 1):
                        if "struct" in lines[j]:
                            while 'test_vec' not in lines[j]:
                                j += 1
                                # get type
                                found = False
                                variable_len = ['1']
                                for rows in range(len(type_list)):
                                    if not found:
                                        for cols in range(len(type_list[rows])):
                                            if type_list[rows][cols] in lines[j]:
                                                v_type = ''
                                                for c in type_list[rows][0]:
                                                    if c.isdigit():
                                                        break
                                                    v_type += c
                                                v_type_list.append(v_type)
                                                found = True
                                                variable_len = re.findall(r'\d+', type_list[rows][0])
                                                break
                                    else:
                                        break
                                # get elements
                                if '[' in lines[j] and '}' not in lines[j]:
                                    v_ele_list.append(variable_len[0]+'x'+lines[j][lines[j].find('[')+1:lines[j].find(']')])
                                    v_name_list.append(lines[j][lines[j].rfind(' ')+1:lines[j].rfind('[')])
                                elif '}' not in lines[j]:
                                    v_ele_list.append(variable_len[0]+'x1')
                                    v_name_list.append(lines[j][lines[j].rfind(' ')+1:lines[j].rfind(';')])
                        if "return" in lines[j]:
                            # Add gen_test function
                            add_content = gen_test(v_type_list, v_ele_list, v_name_list, func_name)
                            lines.insert(j+1, add_content)
                            break
    # Write the modified content back to the file
    with open(file_path, 'w') as file:
        file.writelines(lines)

    pass


if __name__ == '__main__':
    # Open the modify_c.txt file and read its contents
    with open('modify_c.txt', 'r') as modify_c_file:
        file_names = modify_c_file.read().splitlines()

    for file_name in file_names:
        print(f'Start {file_name}')
        main_gen(file_name)
        print(f'Done {file_name}')

